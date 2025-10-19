import PySide6.QtWidgets as QtWidgets
import PySide6.QtGui as QtGui
import time
from main import InternationalizationHelper
import Splash


class MainWindow(QtWidgets.QMainWindow):
    def __init__(self):
        super().__init__()
        self.menu_bar = None

        self.setting_menu = None
        self.language_setting_action = None
        self.quit_setting_action = None

        self.help_menu = None
        self.about_action = None

        self.mode_menu = None

        self.title: str = "ChemistryReactionCalculator"
        self.icon: str = "../resources/image/icon.png"

        self.init_ui()

    def init_ui(self):
        self.setWindowTitle(self.title)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap(self.icon), QtGui.QIcon.Mode.Normal, QtGui.QIcon.State.Off)
        self.setWindowIcon(icon)
        self.resize(1024, 768)

        self.menu_bar = QtWidgets.QMenuBar(self)
        self.setMenuBar(self.menu_bar)

        self.setting_menu = self.menu_bar.addMenu(InternationalizationHelper.translatable_text("menu.setting_menu"))
        self.language_setting_action = QtGui.QAction(InternationalizationHelper.translatable_text("action.language_setting_action"), self)
        self.quit_setting_action = QtGui.QAction(InternationalizationHelper.translatable_text("action.quit_setting_action"), self)
        self.setting_menu.addAction(self.language_setting_action)
        self.setting_menu.addAction(self.quit_setting_action)

        self.help_menu = self.menu_bar.addMenu(InternationalizationHelper.translatable_text("menu.help_menu"))
        self.about_action = QtGui.QAction(InternationalizationHelper.translatable_text("action.about_action"), self)

        self.mode_menu = self.menu_bar.addMenu(InternationalizationHelper.translatable_text("menu.mode_menu"))

        self.help_menu.addAction(self.about_action)

    def create_reaction_input_group(self):
        pass

if __name__ == "__main__":
    app = QtWidgets.QApplication([])
    window = MainWindow()
    splash = Splash.Splash()
    time.sleep(2.5)
    splash.close(window)
    window.raise_()
    window.activateWindow()
    window.show()
    app.exec()