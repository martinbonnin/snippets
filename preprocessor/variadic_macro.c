#define TRIGGER_AA(cb,...) do {\
        AppleAgentListener *aal;\
        list_for_each_entry(aal, &aa->aal_list, link){\
            if (aal->ilistener->cb) {\
                aal->ilistener->cb(aal->priv, ## __VA_ARGS__);\
            }\
        }\
    } while (0);

TRIGGER_AA(rototo);

TRIGGER_AA(retoto,tata)
