/* editor_color_dialog.cpp
 *
 * Color dialog that can be used as an "inline editor" in a table
 *
 * Wireshark - Network traffic analyzer
 * By Gerald Combs <gerald@wireshark.org>
 * Copyright 1998 Gerald Combs
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <ui/qt/widgets/editor_color_dialog.h>

EditorColorDialog::EditorColorDialog(const QModelIndex& index, QWidget* parent)
    : QColorDialog(parent)
    , index_(index)
{

}

EditorColorDialog::EditorColorDialog(const QModelIndex& index, const QColor& initial, QWidget* parent)
    : QColorDialog(initial, parent)
    , index_(index)
{

}

void EditorColorDialog::accept()
{
    emit acceptEdit(index_);
    QColorDialog::accept();
}

/*
 * Editor modelines
 *
 * Local Variables:
 * c-basic-offset: 4
 * tab-width: 8
 * indent-tabs-mode: nil
 * End:
 *
 * ex: set shiftwidth=4 tabstop=8 expandtab:
 * :indentSize=4:tabSize=8:noTabs=true:
 */