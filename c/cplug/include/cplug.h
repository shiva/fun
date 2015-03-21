

typedef enum {
	RC_OK,
	RC_IARGS,
	RC_ERROR
} rc_t;


typedef rc_t (*init_fn)(void);
typedef rc_t (*start_fn)(void);
typedef rc_t (*stop_fn)(void);

typedef struct plugin_s {
	char *id;
	char *name;
	char *version;

	char *provider;
	init_fn init;
	start_fn start;
	stop_fn stop;
} plugin_t;
