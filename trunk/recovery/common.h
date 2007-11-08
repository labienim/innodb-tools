#ifndef common_h
#define common_h

// Table definition types
enum field_type {
	FT_NONE,		// dummy type for stop records
	FT_INTERNAL,	// supported
	FT_CHAR,		// supported (w/o externals)
	FT_INT,			// supported
	FT_UINT,		// supported
	FT_FLOAT,		// supported
	FT_DOUBLE,		// supported
	FT_DATE,		// supported
	FT_DATETIME,	// supported
	FT_ENUM,
	FT_SET,
	FT_BLOB,
	FT_BIT,
	FT_DECIMAL
}; 
typedef enum field_type field_type_t;

typedef struct field_def {
	char *name;
	field_type_t type;
	int min_length;
	int max_length;
	
	ibool can_be_null;
	int fixed_length;
} field_def_t;

#define MAX_TABLE_FIELDS 50

typedef struct table_def {
	char *name;
	field_def_t fields[MAX_TABLE_FIELDS];
	int fields_count;
	int data_min_size;
	int data_max_size;
	int n_nullable;
	int min_rec_header_len;
} table_def_t;

#endif
