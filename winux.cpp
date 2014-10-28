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

#include "winux.hpp"

WinUX::WinUX(QWidget *parent) : QWidget(parent)
{
    QLabel *label = new QLabel("Chargement...");
    QGridLayout *layout = new QGridLayout();
    layout->addWidget(label, 0, 0);
    setLayout(layout);

    QString ImgI = QFileDialog::getOpenFileName(this, "Choisir l'image à convertire", QStandardPaths::writableLocation(QStandardPaths::DesktopLocation), "Images (*.png *.jpg *.jpeg)");

    if(ImgI.isEmpty() || ImgI.isNull())
    {
        QMessageBox::critical(this, "Fichier non trouvée !", "Impossible de trouvée le fichier !");
        exit(1);
    }

     QString ImgO = QFileDialog::getSaveFileName(this, "Choisir l'emplacement de sauvegarde", ImgI, "Images (*.png *.jpg *.jpeg)");

    if(ImgO.isEmpty() || ImgO.isNull())
    {
        ImgO = ImgI;
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

    QMessageBox::information(this, "Yeah !", "Finis !");
}

