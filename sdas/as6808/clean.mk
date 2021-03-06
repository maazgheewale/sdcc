# Deleting all files created by building the program
# --------------------------------------------------
include $(top_builddir)/Makefile.common

clean: mostlyclean
	rm -f *.dep
	rm -f $(ASOBJECTS) $(OBJDIR)/.stamp
	-rmdir $(OBJDIR)

# Deleting all files created by configuring or building the program
# -----------------------------------------------------------------
distclean: clean
	rm -f Makefile

# Like clean but some files may still exist
# -----------------------------------------
mostlyclean:
	rm -f *core *[%~] *.[oa]
	rm -f .[a-z]*~
	rm -f $(top_builddir)/bin/sdas6808$(EXEEXT)

# Deleting everything that can reconstructed by this Makefile. It deletes
# everything deleted by distclean plus files created by bison, etc.
# -----------------------------------------------------------------------
realclean: distclean
