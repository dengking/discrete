from conans import ConanFile, tools
import platform


class ModuleConan(ConanFile):
    name = "singly-linked-list"
    description = "singly-linked-list"
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {
        "shared": False,
        "fPIC": True,
    }
    generators = "cmake"
    exports_sources = "*"

    def requirements(self):
        self.requires("gtest/1.11.0")
