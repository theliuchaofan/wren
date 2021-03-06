// Generated automatically from src/module/scheduler.wren. Do not edit.
static const char* schedulerModuleSource =
"class Scheduler {\n"
"  static add(callable) {\n"
"    if (__scheduled == null) __scheduled = []\n"
"\n"
"    __scheduled.add(Fiber.new {\n"
"      callable.call()\n"
"      runNextScheduled_()\n"
"    })\n"
"  }\n"
"\n"
"  // Called by native code.\n"
"  static resume_(fiber) { fiber.transfer() }\n"
"  static resume_(fiber, arg) { fiber.transfer(arg) }\n"
"  static resumeError_(fiber, error) { fiber.transferError(error) }\n"
"\n"
"  static runNextScheduled_() {\n"
"    if (__scheduled == null || __scheduled.isEmpty) {\n"
"      return Fiber.suspend()\n"
"    } else {\n"
"      return __scheduled.removeAt(0).transfer()\n"
"    }\n"
"  }\n"
"\n"
"  foreign static captureMethods_()\n"
"}\n"
"\n"
"Scheduler.captureMethods_()\n";
