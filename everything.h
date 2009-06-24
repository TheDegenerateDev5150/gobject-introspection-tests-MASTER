#ifndef __GITESTTYPES_H__
#define __GITESTTYPES_H__

#include <glib-object.h>
#include <time.h>

/* basic types */
gboolean test_boolean (gboolean in);
gint8 test_int8 (gint8 in);
guint8 test_uint8 (guint8 in);
gint16 test_int16 (gint16 in);
guint16 test_uint16 (guint16 in);
gint32 test_int32 (gint32 in);
guint32 test_uint32 (guint32 in);
gint64 test_int64 (gint64 in);
guint64 test_uint64 (guint64 in);
gshort test_short (gshort in);
gushort test_ushort (gushort in);
gint test_int (gint in);
guint test_uint (guint in);
glong test_long (glong in);
gulong test_ulong (gulong in);
gssize test_ssize (gssize in);
gsize test_size (gsize in);
gfloat test_float (gfloat in);
gdouble test_double (gdouble in);
time_t test_timet (time_t in);
GType test_gtype (GType in);

/* utf8 */
G_CONST_RETURN char *test_utf8_const_return (void);
char *test_utf8_nonconst_return (void);
void test_utf8_nonconst_in (char *in);
void test_utf8_const_in (const char *in);
void test_utf8_out (char **out);
void test_utf8_inout (char **inout);
GSList *test_filename_return (void);

/* multiple output arguments */
void test_utf8_out_out (char **out0, char **out1);
char *test_utf8_out_nonconst_return (char **out);

/* non-basic-types */
/* array */
gboolean test_strv_in (char **arr);
int test_array_int_in (int n_ints, int *ints);
void test_array_int_out (int *n_ints, int **ints);
int test_array_gint8_in (int n_ints, gint8 *ints);
int test_array_gint16_in (int n_ints, gint16 *ints);
gint32 test_array_gint32_in (int n_ints, gint32 *ints);
gint64 test_array_gint64_in (int n_ints, gint64 *ints);
char *test_array_gtype_in (int n_types, GType *types);
char **test_strv_out_container (void);
char **test_strv_out (void);
const char * const * test_strv_out_c (void);
void   test_strv_outarg (char ***retp);
int test_array_fixed_size_int_in (int *ints);
void test_array_fixed_size_int_out (int **ints);
int *test_array_fixed_size_int_return (void);

/* transfer tests */
int test_array_int_in_take (int n_ints, int *ints);
gboolean test_strv_in_container (char **arr);

int *test_array_int_full_out(int *len);
int *test_array_int_none_out(int *len);

/* interface */
/* GList */
G_CONST_RETURN GList *test_glist_nothing_return (void);
GList *test_glist_nothing_return2 (void);
GList *test_glist_container_return (void);
GList *test_glist_everything_return (void);
void test_glist_nothing_in (const GList *in);
void test_glist_nothing_in2 (GList *in);
void test_glist_container_in (GList *in);
void test_glist_everything_in (GList *in);
void test_glist_free (GList *in);

/* GSList */
G_CONST_RETURN GSList *test_gslist_nothing_return (void);
GSList *test_gslist_nothing_return2 (void);
GSList *test_gslist_container_return (void);
GSList *test_gslist_everything_return (void);
void test_gslist_nothing_in (const GSList *in);
void test_gslist_nothing_in2 (GSList *in);
void test_gslist_container_in (GSList *in);
void test_gslist_everything_in (GSList *in);
void test_gslist_free (GSList *in);

/* GHashTable */
G_CONST_RETURN GHashTable *test_ghash_null_return (void);
G_CONST_RETURN GHashTable *test_ghash_nothing_return (void);
GHashTable *test_ghash_nothing_return2 (void);
GHashTable *test_ghash_container_return (void);
GHashTable *test_ghash_everything_return (void);
void test_ghash_null_in (const GHashTable *in);
void test_ghash_nothing_in (const GHashTable *in);
void test_ghash_nothing_in2 (GHashTable *in);
void test_ghash_container_in (GHashTable *in);
void test_ghash_everything_in (GHashTable *in);
void test_ghash_free (GHashTable *in);
GHashTable *test_ghash_nested_everything_return (void);
GHashTable *test_ghash_nested_everything_return2 (void);

/* error? */

/* closure */
int test_closure (GClosure *closure);
int test_closure_one_arg (GClosure *closure, int arg);

/* value */
int test_int_value_arg(const GValue *v);
const GValue *test_value_return(int i);

/* enums / flags */

typedef enum
{
  TEST_VALUE1,
  TEST_VALUE2,
  TEST_VALUE3 = 42
} TestEnum;

typedef enum
{
  TEST_FLAG1 = 1 << 0,
  TEST_FLAG2 = 1 << 1,
  TEST_FLAG3 = 1 << 2,
} TestFlags;

GType test_enum_get_type (void) G_GNUC_CONST;
#define TEST_TYPE_ENUM (test_enum_get_type ())
GType test_flags_get_type (void) G_GNUC_CONST;
#define TES_TYPE_FLAGS (test_flags_get_type ())

const gchar * test_enum_param(TestEnum e);

/* structures */
typedef struct _TestStructA TestStructA;
typedef struct _TestStructB TestStructB;

struct _TestStructA
{
  gint some_int;
  gint8 some_int8;
  gdouble some_double;
  TestEnum some_enum;
};

void test_struct_a_clone (TestStructA *a,
			  TestStructA *a_out);

struct _TestStructB
{
  gint8 some_int8;
  TestStructA nested_a;
};

void test_struct_b_clone (TestStructB *b,
			  TestStructB *b_out);

/* This one has a non-basic member */
struct _TestStructC
{
  gint another_int;
  GObject *obj;
};

/* plain-old-data boxed types */
typedef struct _TestSimpleBoxedA TestSimpleBoxedA;
typedef struct _TestSimpleBoxedB TestSimpleBoxedB;

struct _TestSimpleBoxedA
{
  gint some_int;
  gint8 some_int8;
  gdouble some_double;
  TestEnum some_enum;
};

GType                   test_simple_boxed_a_get_type     (void);
TestSimpleBoxedA *      test_simple_boxed_a_copy         (TestSimpleBoxedA *a);
gboolean                test_simple_boxed_a_equals       (TestSimpleBoxedA *a,
                                                          TestSimpleBoxedA *other_a);
const TestSimpleBoxedA *test_simple_boxed_a_const_return (void);


struct _TestSimpleBoxedB
{
  gint8 some_int8;
  TestSimpleBoxedA nested_a;
};

GType             test_simple_boxed_b_get_type (void);
TestSimpleBoxedB *test_simple_boxed_b_copy     (TestSimpleBoxedB *b);

/* opaque boxed */
#define TEST_TYPE_BOXED (test_boxed_get_type())

typedef struct _TestBoxed TestBoxed;
typedef struct _TestBoxedPrivate TestBoxedPrivate;

struct _TestBoxed
{
  gint8 some_int8;
  TestSimpleBoxedA nested_a;

  TestBoxedPrivate *priv;
};

GType      test_boxed_get_type (void);
TestBoxed *test_boxed_new      (void);
TestBoxed *test_boxed_copy     (TestBoxed *boxed);
gboolean   test_boxed_equals   (TestBoxed *boxed,
				TestBoxed *other);

/* gobject */
#define TEST_TYPE_OBJ              (test_obj_get_type ())
#define TEST_OBJECT(object)        (G_TYPE_CHECK_INSTANCE_CAST ((object), TEST_TYPE_OBJ, TestObj))
#define TEST_IS_OBJECT(object)     (G_TYPE_CHECK_INSTANCE_TYPE ((object), TEST_TYPE_OBJ))
#define TEST_OBJ_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), TEST_TYPE_OBJ, TestObjClass))

typedef struct _TestObj          TestObj;
typedef struct _TestObjClass     TestObjClass;

/**
 * TestObj:
 * @bare: (allow-none):
 */
struct _TestObj
{
  GObject parent_instance;

  GObject *bare;
  TestBoxed *boxed;
};

struct _TestObjClass
{
  GObjectClass parent_class;

  int (*matrix) (TestObj *obj, const char *somestr);

  guint test_signal;
  guint test_signal_with_static_scope_arg;
};

GType      test_obj_get_type (void);
TestObj*   test_obj_new_from_file (const char *x, GError **error);
void       test_obj_set_bare (TestObj *obj, GObject *bare);
double     test_obj_static_method (int x);

/* virtual */
int        test_obj_do_matrix (TestObj *obj, const char *somestr);

/* callback */
typedef int (*TestCallback) ();
typedef int (*TestCallbackUserData) (gpointer user_data);

int test_callback (TestCallback callback);
int test_callback_user_data (TestCallbackUserData callback,
                             gpointer user_data);
int test_callback_destroy_notify (TestCallbackUserData callback,
                                  gpointer user_data,
                                  GDestroyNotify notify);
int test_callback_thaw_notifications (void);
int test_callback_infinite (TestCallbackUserData callback,
                           gpointer user_data);

/* interface */
#define TEST_TYPE_INTERFACE              (test_interface_get_type ())
#define TEST_INTERFACE(object)           (G_TYPE_CHECK_INSTANCE_CAST ((object), TEST_TYPE_INTERFACE, TestInterface))
#define TEST_IS_INTERFACE(object)        (G_TYPE_CHECK_INSTANCE_TYPE ((object), TEST_TYPE_INTERFACE))
#define TEST_INTERFACE_GET_IFACE(obj)    (G_TYPE_INSTANCE_GET_INTERFACE ((obj), TEST_TYPE_INTERFACE, TestInterfaceIface))

typedef struct _TestInterfaceIface TestInterfaceIface;

struct _TestInterfaceIface {
    GTypeInterface base_iface;
};

GType test_interface_get_type (void) G_GNUC_CONST;

/* gobject with non-standard prefix */
#define TEST_TYPE_WI_802_1X              (test_wi_802_1x_get_type ())
#define TEST_WI_802_1X(object)        (G_TYPE_CHECK_INSTANCE_CAST ((object), TEST_TYPE_WI_802_1X, TestWi8021x))
#define TEST_IS_WI_802_1X(object)     (G_TYPE_CHECK_INSTANCE_TYPE ((object), TEST_TYPE_WI_802_1X))
#define TEST_WI_802_1X_GET_CLASS(obj)    (G_TYPE_INSTANCE_GET_CLASS ((obj), TEST_TYPE_WI_802_1X, TestWi8021xClass))

typedef struct
{
  GObject parent_instance;

  gboolean testbool;
} TestWi8021x;

typedef struct
{
  GObjectClass parent_class;
} TestWi8021xClass;

GType        test_wi_802_1x_get_type (void);
TestWi8021x* test_wi_802_1x_new (void);
gboolean     test_wi_802_1x_get_testbool (TestWi8021x *obj);
void         test_wi_802_1x_set_testbool (TestWi8021x *obj, gboolean v);
int          test_wi_802_1x_static_method (int x);

#endif /* __GITESTTYPES_H__ */
