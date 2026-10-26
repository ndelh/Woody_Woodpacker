{ pkgs ? import <nixpkgs> {} }:

pkgs.pkgsi686Linux.mkShell {
  buildInputs = [
    # Ajoutez vos bibliothèques 32 bits ici si besoin
  ];
}
