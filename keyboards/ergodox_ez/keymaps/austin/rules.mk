STENO_ENABLE = yes
STENO_PROTOCOL = geminipr
NKRO_ENABLE = yes
FORCE_NKRO = yes

ifeq (${FORCE_NKRO},yes)
OPT_DEFS += -DFORCE_NKRO
endif
