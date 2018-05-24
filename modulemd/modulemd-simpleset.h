/* modulemd-simpleset.h
 *
 * Copyright (C) 2017 Stephen Gallagher
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MODULEMD_SIMPLESET_H
#define MODULEMD_SIMPLESET_H

#include <glib-object.h>

G_BEGIN_DECLS

#define MODULEMD_TYPE_SIMPLESET modulemd_simpleset_get_type ()
G_DECLARE_FINAL_TYPE (
  ModulemdSimpleSet, modulemd_simpleset, MODULEMD, SIMPLESET, GObject)

ModulemdSimpleSet *
modulemd_simpleset_new (void);

gboolean
modulemd_simpleset_contains (ModulemdSimpleSet *self, const gchar *value);
guint
modulemd_simpleset_size (ModulemdSimpleSet *self);

void
modulemd_simpleset_set (ModulemdSimpleSet *self, gchar **set);
gchar **
modulemd_simpleset_get (ModulemdSimpleSet *self);
gchar **
modulemd_simpleset_dup (ModulemdSimpleSet *self);

void
modulemd_simpleset_add (ModulemdSimpleSet *self, const gchar *value);

void
modulemd_simpleset_remove (ModulemdSimpleSet *self, const gchar *value);

void
modulemd_simpleset_copy (ModulemdSimpleSet *self, ModulemdSimpleSet **dest);

gboolean
modulemd_simpleset_is_equal (ModulemdSimpleSet *self,
                             ModulemdSimpleSet *other);

/**
 * SimpleSetValidationFn:
 * @str: The current string being validated from the set
 *
 * This function is called once for each string in a #ModulemdSimpleSet
 * when the validate_contents() routine is invoked. It must return TRUE
 * if the string passes validation or FALSE if it does not.
 *
 * Since: 1.4
 */
typedef gboolean (*ModulemdSimpleSetValidationFn) (const gchar *str);

gboolean
modulemd_simpleset_validate_contents (ModulemdSimpleSet *self,
                                      ModulemdSimpleSetValidationFn func,
                                      GPtrArray **failures);

G_END_DECLS

#endif /* MODULEMD_SIMPLESET_H */
