{
  description = "Lafeychine's Talks";

  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, flake-utils, nixpkgs }:

    flake-utils.lib.eachDefaultSystem (system:
      let
        pkgs = nixpkgs.legacyPackages.${system};
        fonts = pkgs.makeFontsConf {
          fontDirectories = with pkgs; [ lmodern fira fira-mono ];
        };
      in {
        devShell = pkgs.mkShell {
          buildInputs = with pkgs; [
            emacs
            inkscape
            gnuplot
            python3Packages.pygments
            texlive.combined.scheme-full
          ];

          shellHook = ''
            export FONTCONFIG_FILE=${fonts}
          '';
        };
      });
}
