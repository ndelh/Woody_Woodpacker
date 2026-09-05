/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify_core.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndelhota <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 18:27:45 by ndelhota          #+#    #+#             */
/*   Updated: 2026/08/26 18:28:00 by ndelhota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../woody_woodpacker.h"

void    destroy_shdr(t_intel *intel)
{
    const t_elf_ops   *elf_caster;
    void        *cursor;

    cursor = intel->ogn_begin;
    elf_caster = intel->elf_caster;
    iterate_shdr(intel, shdr_destruct);
    elf_caster->set_shdr_nb(cursor, 0);
    elf_caster->set_shdr_offset(cursor, 0);
    elf_caster->set_shdr_size(cursor, 0);
    elf_caster->set_shstrndx(cursor, 0);
}

void    join_stub_intel(t_intel *intel, t_intel *stub)
{
    t_stub_loader   *stub_intel;
    t_stub_loader   *stub_stub;

    stub_intel = &intel->stub_loader;
    stub_stub = &stub->stub_loader;

    stub_intel->content_begin = stub_stub->content_begin;
    stub_intel->content_size = stub_stub->content_size;
    stub_intel->placeholder_begin = stub_stub->placeholder_begin;
    stub_intel->shdr_header_inject = stub_stub->shdr_header_inject;
}

void	modify_core(t_intel *intel)
{
    t_intel stub;

	printf("intel for: %s \n", intel->binary_name);
    gather_ehdr(intel);
    print_edhr_intel(intel);
    ft_bzero(&stub, sizeof(t_intel));
    stub.binary_name = STUBNAME;
    gather_stub_intel(intel, &stub);
    fetch_modify_need(intel, &stub);
    destroy_shdr(intel);
    iterate_phdr(intel, retrieve_available_adrr);
    join_stub_intel(intel, &stub);//this one is proof that code need serious refactorisation
    reproduce(intel);
}
