/*
     Copyright (C) 2014 Muller Romain

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.

*/

#include <QtWidgets/QtWidgets>
#include <QtWidgets/QFileDialog>
#include <QtGui/QImage>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QDialog *win = new QDialog;

    QString ImgI = QFileDialog::getOpenFileName(win, "Choisir l'image à convertire", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "Images (*.png *.jpg *.jpeg)");

    if(ImgI.isEmpty() || ImgI.isNull())
    {
        QMessageBox::critical(win, "Fichier non trouvée !", "Impossible de trouvée le fichier !");
        exit(EXIT_FAILURE);
    }

     QString ImgO = QFileDialog::getSaveFileName(win, "Choisir l'emplacement de sauvegarde", ImgI, "Images (*.png *.jpg *.jpeg)");

    if(ImgO.isEmpty() || ImgO.isNull())
    {
        QMessageBox::critical(win, "Fichier non trouvée !", "Impossible de trouvée le fichier !");
        exit(EXIT_FAILURE);
    }

    QImage tmpImg(ImgI);

    for(int x(0); x < tmpImg.width(); x++)
    {
        for(int y(0); y < tmpImg.height(); y++)
        {
            QRgb rgb = tmpImg.pixel(x, y);

            if(rgb > 0xFFC8C8C8)
            {
                tmpImg.setPixel(x, y, 0xFFFFFF);
            }
        }
    }

    tmpImg.save(ImgO);

    QMessageBox::information(win, "Yeah !", "Finis !");

    exit(EXIT_SUCCESS);

    return app.exec();
}
