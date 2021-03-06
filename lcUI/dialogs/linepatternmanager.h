#pragma once

#include <cad/document/document.h>

#include <QDialog>
#include <QHeaderView>

#include <dialogs/addlinepatterndialog.h>
#include <widgets/linepatternmodel.h>

namespace Ui {
    class LinePatternManager;
}
/**
 * \brief Create a new window which shows a list of line patterns
 */
class LinePatternManager : public QDialog {
    Q_OBJECT

    public:
        /**
         * \brief Create window
         * \param document Document which contains the DXFLinePatterns
         * \param parent Parent widget
         */
        LinePatternManager(lc::Document_SPtr document, QWidget* parent = 0);
        ~LinePatternManager();

        /**
         * \brief Set a new document
         * and update the list of line patterns.
         * Document can be set to nullptr to clear the list.
         * \param document Document or nullptr
         */
        void setDocument(lc::Document_SPtr document);

    private slots:
        /**
         * \brief Create update dialog.
         * This function is called when "Edit" button is pressed.
         * It create a new dialog pre-filled with the line pattern informations.
         */
        void on_editButton_pressed();
        /**
         * \brief Create new line pattern dialog.
         * It create a new dialog to create a line pattern.
         * This function is called when "New" button is pressed.
         */
        void on_newButton_pressed();
        /**
         * \brief Create update dialog.
         * It create a new dialog pre-filled with the line pattern informations.
         * This function is called when an element of the list is double clicked.
         */
        void on_lpView_doubleClicked(const QModelIndex& index);

    private:
        /**
         * \brief Refresh line patterns list.
         */
        void updateModel();

        Ui::LinePatternManager* ui;
        lc::Document_SPtr _document;
        LinePatternModel* _model;

        void on_addLinePatternEvent(const lc::AddLinePatternEvent&);
        void on_removeLinePatternEvent(const lc::RemoveLinePatternEvent&);
        void on_replaceLinePatternEvent(const lc::ReplaceLinePatternEvent&);
};