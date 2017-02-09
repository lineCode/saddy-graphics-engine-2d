#include<string>
extern const std::string __context_eval_info;
const std::string __context_eval_info = std::string("var sad = {};\n"
"sad.internal = {};\n"
"sad.util = {};\n"
"\n"
"sad.Point2D = SadPoint2D;\n"
"sad.Point3D = SadPoint3D;\n"
"sad.Point2I = SadPoint2I;\n"
"sad.Point3I = SadPoint3I;\n"
"\n"
"\n"
"sad.internal.plus = function(a, b) { return a + b; };\n"
"sad.internal.minus = function(a, b) { return a - b; };\n"
"sad.internal.multiply = function(a, b) { return a * b; };\n"
"sad.internal.divide = function(a, b) { return a / b; };\n"
"\n"
"\n"
"sad.internal.copyObject = function(dest, src) {\n"
"    for(var key in src) {\n"
"        if (src.hasOwnProperty(key)) {\n"
"            dest[key] = src[key];\n"
"        }\n"
"    }\n"
"}\n"
"\n"
"sad.internal.makeMathFns = function(obj) {\n"
"    obj.plus = function(o) {\n"
"        return this.makeWithFn(sad.internal.plus, o);\n"
"    };\n"
"\n"
"    obj.minus = function(o) {\n"
"        return this.makeWithFn(sad.internal.minus, o);\n"
"    };\n"
"\n"
"    obj.multiply = function(o) {\n"
"        return this.makeWithFn(sad.internal.multiply, o);\n"
"    };\n"
"\n"
"    obj.divide = function(o) {\n"
"        return this.makeWithFn(sad.internal.divide, o);\n"
"    };\n"
"};\n"
"\n"
"//  sad.Point2D bindings\n"
"\n"
"sad.Point2D.prototype.to3d = function() {\n"
"    return new sad.Point3D(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.Point2D.prototype.to3i = function() {\n"
"    return new sad.Point3I(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.Point2D.prototype.to2i = function() {\n"
"    return new sad.Point2I(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point2D.prototype.makeWithFn = function(fn, o) {\n"
"    return new sad.Point2D(fn(this.x, o.x), fn(this.y, o.y));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.Point2D.prototype);\n"
"\n"
"sad.Point2D.prototype.toString = function() {\n"
"    return \"sad::Point2D(\" + this.x + ',' + this.y + ')';\n"
"};\n"
"\n"
"//  sad.Point3D bindings\n"
"\n"
"sad.Point3D.prototype.to2d = function() {\n"
"    return new sad.Point2D(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point3D.prototype.to2i = function() {\n"
"    return new sad.Point2I(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point3D.prototype.to3I = function() {\n"
"    return new sad.Point3I(this.x, this.y, this.z);\n"
"};\n"
"\n"
"\n"
"sad.Point3D.prototype.makeWithFn = function(fn, o) {\n"
"    return new sad.Point3D(fn(this.x, o.x), fn(this.y, o.y), fn(this.z, o.z));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.Point3D.prototype);\n"
"\n"
"sad.Point3D.prototype.toString = function() {\n"
"    return \"sad::Point3D(\" + this.x + ',' + this.y + ',' + this.z + ')';\n"
"};\n"
"\n"
"// sad.Point2I \n"
"\n"
"sad.Point2I.prototype.to2d = function() {\n"
"    return new sad.Point2D(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point2I.prototype.to3d = function() {\n"
"    return new sad.Point3D(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.Point2I.prototype.to3i = function() {\n"
"    return new sad.Point3I(this.x, this.y, 0);\n"
"};\n"
"\n"
"\n"
"sad.Point2I.prototype.makeWithFn = function(fn, o) {\n"
"    return new sad.Point2I(fn(this.x, o.x), fn(this.y, o.y));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.Point2I.prototype);\n"
"\n"
"sad.Point2I.prototype.toString = function() {\n"
"    return \"sad::Point2I(\" + this.x + ',' + this.y  + ')';\n"
"};\n"
"\n"
"// sad.Point3I\n"
"\n"
"sad.Point3I.prototype.to2d = function() {\n"
"    return new sad.Point2D(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point3I.prototype.to2i = function() {\n"
"    return new sad.Point2I(this.x, this.y);\n"
"};\n"
"\n"
"sad.Point3I.prototype.to3d = function() {\n"
"    return new sad.Point3D(this.x, this.y, this.z);\n"
"};\n"
"\n"
"\n"
"sad.Point3I.prototype.makeWithFn = function(fn, o) {\n"
"    return new sad.Point3I(fn(this.x, o.x), fn(this.y, o.y), fn(this.z, o.z));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.Point3I.prototype);\n"
"\n"
"sad.Point3I.prototype.toString = function() {\n"
"    return \"sad::Point3I(\" + this.x + ',' + this.y + ',' + this.z + ')';\n"
"};\n"
"\n"
"// sad.p2d.Vector bindings\n"
"\n"
"sad.p2d = {};\n"
"sad.p2d.Vector = SadP2DVector;\n"
"\n"
"\n"
"sad.p2d.Vector.prototype.to3d = function() {\n"
"    return new sad.Point3D(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.p2d.Vector.prototype.to3i = function() {\n"
"    return new sad.Point3I(this.x, this.y, 0);\n"
"};\n"
"\n"
"sad.p2d.Vector.prototype.to2i = function() {\n"
"    return new sad.Point2I(this.x, this.y);\n"
"};\n"
"\n"
"sad.p2d.Vector.prototype.makeWithFn = function(fn, o) {\n"
"    return new sad.Point2D(fn(this.x, o.x), fn(this.y, o.y));\n"
"};\n"
"\n"
"sad.internal.makeMathFns(sad.p2d.Vector.prototype);\n"
"\n"
"sad.p2d.Vector.prototype.toString = function() {\n"
"    return \"sad::p2d::Vector(\" + this.x + ',' + this.y + ')';\n"
"};\n"
"\n"
"sad.p2d.modulo = SadP2DModulo;\n"
"sad.p2d.basis = SadP2DBasis;\n"
"sad.p2d.unit = SadP2DUnit;\n"
"sad.p2d.scalar = SadP2DScalar;\n"
"sad.p2d.ortho = SadP2DOrtho;\n"
"sad.p2d.OVI_DEG_90 = 0;\n"
"sad.p2d.OVI_DEG_270 = 1;\n"
"\n"
"// sad.Size2D\n"
"\n"
"sad.Size2D = SadSize2D;\n"
"sad.Size2D.prototype.to2i = function() {\n"
"    return new sad.Size2I(this.width, this.height);\n"
"};\n"
"sad.Size2D.prototype.toString = function() {\n"
"    return \"sad::Size2D(\" + this.width + ',' + this.height + ')';\n"
"};\n"
"\n"
"// sad.Size2I\n"
"\n"
"sad.Size2I = SadSize2I;\n"
"sad.Size2I.prototype.to2d = function() {\n"
"    return new sad.Size2D(this.width, this.height);\n"
"};\n"
"sad.Size2I.prototype.toString = function() {\n"
"    return \"sad::Size2I(\" + this.width + ',' + this.height + ')';\n"
"};\n"
"\n"
"// sad.Rect2D\n"
"\n"
"sad.Rect2D = SadRect2D;\n"
"\n"
"sad.Rect2D.prototype.to2i = function() {\n"
"    return new sad.Rect2I(this.p0().to2i(), this.p1().to2i(), this.p2().to2i(), this.p3().to2i());\n"
"};\n"
"sad.Rect2D.prototype.toString = function() {\n"
"    var result = [];\n"
"    for(var i = 0; i < 4; i++)\n"
"    {\n"
"        result.push(sad.Point2D.prototype.toString.call(this['p' + i]()));\n"
"    }\n"
"    return \"sad::Rect2D(\" +  result.join(', ') + ')';\n"
"};\n"
"\n"
"// sad.Rect2I\n"
"\n"
"sad.Rect2I = SadRect2I;\n"
"\n"
"sad.Rect2I.prototype.to2d = function() {\n"
"    return new sad.Rect2D(this.p0().to2d(), this.p1().to2d(), this.p2().to2d(), this.p3().to2d());\n"
"};\n"
"sad.Rect2I.prototype.toString = function() {\n"
"    var result = [];\n"
"    for(var i = 0; i < 4; i++)\n"
"    {\n"
"        result.push(sad.Point2I.prototype.toString.call(this['p' + i]()));\n"
"    }\n"
"    return \"sad::Rect2I(\" +  result.join(', ') + ')';\n"
"};\n"
"\n"
"\n"
"// console object\n"
"\n"
"var console = {};\n"
"console.dump = function(o) {\n"
"    var type = typeof o;\n"
"    if (type == \"undefined\") { return \"undefined\"};\n"
"    if ((type == \"boolean\") || (type == \"number\") || (type == \"string\") || (type == \"symbol\") || (type == \"function\")) { return o.toString();}\n"
"    if (type == \"object\")\n"
"    {\n"
"        if (o === null)\n"
"        {\n"
"            return \"null\";\n"
"        }\n"
"        if (o instanceof Array)\n"
"        {\n"
"            var  i = 0; \n"
"            var  result = [];\n"
"            for(var i = 0; i < o.length; i++)\n"
"            {\n"
"                if (i in o)\n"
"                {\n"
"                    result.push(console.dump(o[i]));\n"
"                }\n"
"            }\n"
"            return \"[\" + result.join(\", \") + \"]\";\n"
"        }\n"
"        else\n"
"        {\n"
"            if (SadInternalIsNativeObject(o))\n"
"            {\n"
"                if (o.hasOwnProperty('toString'))\n"
"                {\n"
"                    return o.toString();\n"
"                } \n"
"                var hasPrototypeToString = false;\n"
"                if (typeof o.prototype != \"undefined\")\n"
"                {\n"
"                    hasPrototypeToString = (o.prototype.hasOwnProperty('toString') && o.prototype.toString != Object.toString);\n"
"                }\n"
"                if (hasPrototypeToString)\n"
"                {\n"
"                    return o.toString();\n"
"                }\n"
"                return SadInternalDumpNativeObject(o);\n"
"            }\n"
"            else\n"
"            {\n"
"                if (o.hasOwnProperty('toString'))\n"
"                {\n"
"                    return o.toString();\n"
"                }\n"
"                else\n"
"                {\n"
"                    var asString = o.toString();\n"
"                    if (asString != \"[object Object]\")\n"
"                    {\n"
"                        return asString;\n"
"                    }\n"
"                    else\n"
"                    {\n"
"                        var result = [];\n"
"                        for(var key in o) { result.push(\"\\\"\" + key + \"\\\"\" + ' : ' + console.dump(o[key]));}\n"
"                    }\n"
"                }\n"
"                return \"{\" + result.join(\", \") + \"}\";\n"
"            }\n"
"        }\n"
"    }\n"
"    return \"\";\n"
"};\n"
"\n"
"console.log = function(o)\n"
"{\n"
"    print(console.dump(o));\n"
"};\n"
"\n"
"// sad.util and sad.fs\n"
"sad.fs = {};\n"
"\n"
"sad.fs.pathDelimiter = SadUtilPathDelimiter;\n"
"sad.fs.canonicalizePath = SadUtilCanonicalizePath;\n"
"sad.fs.isAbsolutePath = SadUtilIsAbsolutePath;\n"
"sad.fs.concatPaths = SadUtilConcatPaths;\n"
"sad.fs.folder = SadUtilFolder;\n"
"sad.fs.fileExists = SadUtilFileExists;\n"
"sad.internal.copyObject(sad.util, sad.fs);\n"
"\n"
"// sad.spit and sad.slurp\n"
"\n"
"sad.spit = SadSpit;\n"
"sad.slurp = SadSlurp;\n"
"\n"
"sad.spitJSON = function(a, obj) {\n"
"    return sad.spit(a, JSON.stringify(obj, null, 2));\n"
"};\n"
"\n"
"sad.slurpJSON = function(o) {\n"
"    var  r = sad.slurp(o);\n"
"    if (r !== null) {\n"
"        return JSON.parse(r);\n"
"    }\n"
"    return null;\n"
"};\n"
"\n"
"\n"
"// context\n"
"\n"
"context.evalFromFile = function(string) {\n"
"    var s = sad.slurp(string);\n"
"    if (s == null) {\n"
"        throw new Error(\"Cannot read file \\\"\" + string + \"\\\"\");\n"
"    }\n"
"    return eval(s);\n"
"};\n"
"\n"
"context.eval = function(string) {\n"
"    return eval(string);\n"
"};\n"
"\n"
"sad.Context = SadContext;\n"
"\n"
"sad.Context.prototype.eval = function(string) {\n"
"    return SadContextEval(this, string);\n"
"};\n"
"\n"
"sad.Context.prototype.evalFromFile = function(string) {\n"
"    return SadContextEvalFromFile(this, string);\n"
"};\n"
"\n"
"// sad.Renderer bindings\n"
"\n"
"sad.Renderer = SadRenderer;\n"
"\n"
"sad.Renderer.ref = SadRendererRef;\n"
"sad.Renderer.makeFPSInterpolationDefault = function() {  SadInternalMakeFPSInterpolationDefault(this); }\n"
"sad.Renderer.makeFPSInterpolationObjectDependent = function() {  SadInternalMakeFPSInterpolationObjectDependent(this); }\n"
"\n"
"// sad.Settings bindings\n"
"\n"
"sad.Settings = SadSettings;\n"
"\n"
"// sad.Timer bindings\n"
"\n"
"sad.Timer = SadTimer;\n"
"\n"
"sad.Timer.prototype.elapsedInMs = function() {\n"
"    this.stop();\n"
"    return this.elapsed();\n"
"};\n"
"\n"
"// sad.Thread bindings\n"
"\n"
"sad.Thread = SadThread;\n"
"\n"
"// sad.Color bindings\n"
"\n"
"sad.Color = SadColor;\n"
"\n"
"sad.internal.uCharToInt = function(a) {\n"
"    if (a.length == 0) {\n"
"        return 0;\n"
"    }\n"
"    return a[0].charCodeAt(0);\n"
"}\n"
"\n"
"sad.Color.prototype.toString = function() {\n"
"    var o =  [ sad.internal.uCharToInt(this.r),  sad.internal.uCharToInt(this.g), sad.internal.uCharToInt(this.b) ]; \n"
"    return \"sad::Color(\" + o.join(', ')  + \")\";\n"
"}\n"
"\n"
"sad.AColor = SadAColor;\n"
"\n"
"sad.AColor.prototype.toString = function() {\n"
"    var o =  [ sad.internal.uCharToInt(this.r),  sad.internal.uCharToInt(this.g), sad.internal.uCharToInt(this.b), sad.internal.uCharToInt(this.a) ]; \n"
"    return \"sad::AColor(\" + o.join(', ')  + \")\";\n"
"}\n"
"\n"
"// sad.log.Log bindings\n"
"\n"
"sad.log = {};\n"
"sad.log.Log = SadLog;\n"
"sad.log.Log.prototype.ref = SadLogRef;\n"
"sad.log.Log.prototype.addTarget = function(a) { SadInternalLogAddTarget(this, a); }\n"
"sad.log.Log.prototype.removeTarget = function(a) { SadInternalLogRemoveTarget(this, a); }\n"
"\n"
"sad.log.Priority = {\n"
"    \"FATAL\" : 6, \n"
"    \"CRITICAL\" : 5, \n"
"    \"WARNING\" : 4,\n"
"    \"MESSAGE\" : 3, \n"
"    \"DEBUG\" : 2, \n"
"    \"USER\" : 1, \n"
"    \"SADDY_INTERNAL\" : 0  \n"
"};\n"
"\n"
"sad.log.ConsoleTarget = SadLogConsoleTarget;\n"
"sad.log.FileTarget = SadLogFileTarget;\n"
"\n"
"sad.sleep = SadSleep;\n"
"sad.Mutex = SadMutex;\n"
"sad.Semaphore = SadSemaphore;\n"
"\n"
"sad.MouseCursor = SadMouseCursor;\n");