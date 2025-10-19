import PySide6.QtCore as QtCore
import PySide6.QtGui as QtGui
import PySide6.QtWidgets as QtWidgets


class Splash:
    def __init__(self):
        screen = QtWidgets.QApplication.primaryScreen()
        screen_rect = screen.availableGeometry()
        self.screen_width = screen_rect.width()
        self.screen_height = screen_rect.height()

        original_pixmap = QtGui.QPixmap("../resources/image/splash.png")
        scale_factor = 0.3
        pixmap = original_pixmap.scaled(int(self.screen_width * scale_factor),
                                        int(self.screen_width * scale_factor / original_pixmap.width()
                                            * self.screen_height),
                                        QtCore.Qt.AspectRatioMode.KeepAspectRatio,
                                        QtCore.Qt.TransformationMode.SmoothTransformation)
        self.splash = QtWidgets.QSplashScreen(pixmap)
        self.splash.show()

    def close(self, app):
        self.splash.finish(app)
