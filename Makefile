NAME		:=	Vincent LAFEYCHINE
export NAME

EMACS		:=	emacs
EMACSFLAGS	:=	-Q --eval "(setq org-latex-listings 'minted)" --batch -f org-beamer-export-to-latex --kill

TEX		:=	xelatex
TEXFLAGS	:=	--shell-escape -interaction=batchmode -halt-on-error -output-driver='xdvipdfmx -z9'

PROJECTS	:=	Epitech_MAT/101pong/Bootstrap		\
			Epitech_MAT/101pong/FollowUp		\
			Epitech_MAT/102architect/KickOff	\
			Epitech_MAT/102architect/Bootstrap	\
			Epitech_MAT/102architect/FollowUp	\
			Epitech_MAT/103cipher/KickOff		\
			Epitech_MAT/103cipher/Bootstrap		\
			Epitech_MAT/103cipher/FollowUp		\
			Epitech_MAT/105torus/Bootstrap		\
			Epitech_MAT/106bombyx/Bootstrap		\
			Epitech_MAT/108trigo/Bootstrap		\
			Epitech_MAT/109titration/Bootstrap	\
			Epitech_MAT/110borwein/Bootstrap	\
			Epitech_MAT/201yams/Bootstrap		\
			Epitech_MAT/202unsold/Bootstrap		\
			Epitech_MAT/203hotline/Bootstrap	\
			Epitech_MAT/204ducks/Bootstrap		\
			Epitech_MAT/206neutrinos/Bootstrap	\
			Epitech_MAT/207demography/Bootstrap	\
			Epitech_MAT/208dowels/Bootstrap		\
			Epitech_MAT/304pacman/Bootstrap		\
			Epitech_MAT/305construction/Bootstrap	\
			Epitech_MAT/306radiator/Bootstrap	\
			Epitech_MAT/307multigrains/Bootstrap	\
			Epitech_MAT/308reedpipes/Bootstrap	\
			Epitech_MAT/309pollution/Bootstrap	\
			Epitech_PSU/UnitPresentation		\
			Epitech_PSU/Bootstrap_STrace		\
			Epitech_PSU/Bootstrap_FTrace		\
			Malloc/Talk				\
			Malloc/Talk_Algorithms

PDF		:=	$(PROJECTS:=.pdf)


all:		$(PDF)

%.pdf:		%.tex
		cd $(^D) && $(TEX) $(TEXFLAGS) $(^F)

%.tex:		%.org
		$(EMACS) $^ $(EMACSFLAGS)

clean:
		git clean -dfx

.PHONY:		all clean
.PRECIOUS:	%.tex
