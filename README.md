# 🌱 Weed-Detector

The objective of the project is to develop an application that generates the georeferencing of an aerial image, either by Google Earth or through the operator, which introduces the latitudes and longitudes of three points, which are necessary as a minimum for georeferencing.

## ✒️Project description

The purpose of georeferencing is to locate the sectors in space and to be able to carry out an analysis of the real dimensions of the areas to be sprayed.
Once this is done, the application creates a map of the lot that indicates where the agrochemical should not be applied and where it should. The application detects the green areas of the image with adequate precision and then encloses these areas with polygons.

These polygons make up a shapefile file, which will be downloaded to the sprayer which will perform a specific site application of the product, thus avoiding product waste or excessive spraying.

## 📊Description of the tools

### Python

The use of this language was used in the first instance due to its simplicity for the creation of raster files and the creation of polygon shapefile files. For later its subsequent passage to C ++.

It is a multi-paradigm programming language, since rather than forcing programmers to adopt a particular programming style, it allows several styles: object orientation, imperative programming and, to a lesser extent, functional programming.

Python is an interpreted, cross-platform, and object-oriented programming language created in the early 90s. It is characterized by having a clear syntax (which gives good readability to the code), by having dynamic typing (it is not necessary to declare the type of the variables) and for being strongly typed (you cannot treat a variable as if it were of a different type than the one it has).
Another goal of language design is ease of extension. New modules can be easily written in C or C++. Python can be included in applications that need a programmable interface.

It is a very powerful language that has ventured into many fields, making it easy to develop functionalities and plug-ins. Interpreted programming languages are slower than compiled languages, because an interpreter must translate the script each time it is executed. However, Python handles a mechanism similar to that of Java, passing the source code to an intermediate code so that this is the one that is executed before any subsequent call.

### QGIS or Quantum GIS

It is an open source Geographic Information System (GIS) for GNU/Linux, Unix, Mac OS and Microsoft Windows platforms. QGIS is developed in C++, using the Qt library for its Graphical User Interface. Quantum GIS allows the integration of plugins developed in both C++ and Python.
It allows handling raster and vector formats through the GDAL and OGR libraries, as well as databases.
Some of its features are support for spatial extension, handling of Shapefile vector files among others, and support for an important number of raster file types (GeoTIFF, TIFF, JPG, etc.)

The Quantum GIS GIS libraries are a set of C++ classes that allow you to access and manipulate the spatial objects that a GIS program needs. The bookstores are:
• Core: Contains the GIS functionalities.
• Gui: It is built on the Core library. Contains reusable controls for the user interface such as the Map Canvas, the region in which the map is displayed and manipulated.
• MapComposer (Map Generation): Contains functionalities to generate graphic outputs.
• Geospatial Data Abstraction Library or GDAL

Software library for reading and writing geospatial data formats. As a library, it presents a single abstract data model for calling use for all supported formats. It also comes with a variety of command line utilities for translation and processing of geospatial data.

### PyQGIS and PyQt

One of the great strengths of Python is its ability to take existing libraries, written in C and C++, and make them available as extension modules. These extension modules are known as Bindings for the library.
For example, Quantum GIS is written in C++, but provides bindings (PyQGIS) that allow you to develop stand-alone desktop applications and plug-ins for Quantum GIS using Python.

For the development of the Shapefiles viewer, the following bindings will be used:

• PyQt4: Bindings for Qt4. They allow you to make use of many of the classes and user interface objects of the Qt4 project from within Python. It has a dual license, like Qt, that is, it has a GPL version and a commercial version that allows development to be closed.
• PyQGIS: Bindings for QGIS. They are provided by the Quantum GIS project since its version 0.9 in September 2007. According to Martin Dobias, developer of the mentioned GIS program, PyQGIS is 99% identical to the Application Programming Interface (API) in C++. PyQGIS is built into the QGIS 1.0 installer.

### QtCreator

Qt Creator is a cross-platform IDE (integrated development environment) that comes with Qt libraries built-in and meets the needs of increasing the ability to display Qt data clearly and generate the program's graphical interface. It is written in C++. It is characterized because it allows compiled projects to be executed on various platforms such as GNU/Linux, Mac OS X and Windows.

• Signals and Slots

The signals and slots mechanism is a core feature of Qt and is used for communication between objects. In Qt, this callback technique using signals and spots is based on the fact that a signal is emitted when a particular event occurs and a slots is a function that is called in response to a particular signal.

Qt's Signals and slots mechanism ensures that if you connect a signal to a slot, the slot will be called with the signal's parameters at the appropriate time. Slots can be used to receive signals, but they are also normal member functions. The signals and slots mechanism is type-safe: The signature of a signal must match the signature of the receiving slot

• Meta-Object compiler

The Meta-Object compiler, MOC, is the program that takes care of Qt's C++ extensions. This tool reads the C++ header file, if it finds one or more class declarations that contain the Q_OBJECT macro, it produces a C++ source file that contains the meta-object code for those classes. Among other things, meta-object code is required for the signals and slots mechanism, the run-time type information, and the dynamic property system. The C++ source file generated by MOC is compiled and linked to the implementation class.

### OpenCV

The main analysis and graphic processing tool used is OpenCV, which is a multiplatform library oriented to computer vision.
OpenCV has numerous modules for various applications, among which we can highlight: facial recognition, gesture recognition, object identification, object trekking and segmentation, and pattern recognition.

This project mainly uses image processing functions to binarize, erode, dilate, open and close the image of others.

### Considerations

To access Windows environment (system) variables, the following steps must be followed. In order to avoid future inconveniences in terms of software for the next interns:
-Control Panel
-System.
-In the advanced options tab, click "Environment Variables".
-The “Path”, in system variables, is the following:

C:\Python27\;C:\Inprise\vbroker\bin;C:\ARCHIV~1\Borland\CBUILD~1\Projects\Bpl;C:\ARCHIV~1\Borland\CBUILD~1\Bin;C:\ WINDOWS\system32;C:\WINDOWS;C:\WINDOWS\System32\Wbem;C:\Program Files\CMake\bin;C:\Program Files\mingw-w64\mingw32\bin;C:\Qt\4.8 .6\bin;C:\Program Files\GDAL;C:\Documents and Settings\Administrator\Desktop\Project Weeds\opencv\build\x86\MinGW\bin

You have to try not to modify this path within the QtCreator program, since within it it also has the ability to change it. That would make the software created unable to run inside Qt. For this reason it is recommended that if you need to change the environment variables, you change the system ones and not the Qt ones.

## 💻 Algorithms

### Georeferencing

With the Qgis plugin, called Georeferencer, this is the configuration we use to georeference any image, in this case the Rosario Victoria bridge. Where we can see the type of transformation and resampling that we find most useful because it faithfully respects the proportions of the reference image, which is a google earth map opened from Qgis.

![image](https://user-images.githubusercontent.com/105976212/219904586-0529b803-b2cf-475b-8927-8ecdab922d12.png)

Then we use the possibility of exporting a script, which would be equivalent to the procedure carried out by Qgis.

![image](https://user-images.githubusercontent.com/105976212/219904616-1922b993-505c-4f6a-9726-f4b28c918ded.png)

![image](https://user-images.githubusercontent.com/105976212/219904625-fb5559b2-46dd-4e9b-81cd-210d0e0bbf47.png)

-6.75615e+06 -3.87768e+06 "C:/Documents and Settings/Administrator/Desktop/Guillermo/RosarioVictoria_40cm_pixel.jpg" "C:/Windows/Temp/RosarioVictoria_40cm_pixel.jpg"
gdalwarp -r near -order 1 -co COMPRESS=NONE "C:/Windows/Temp/RosarioVictoria_40cm_pixel.jpg" "C:/Documents and Settings/Administrator/Desktop/Guillermo/RosarioVictoriaBB_40cm_pixel_modified 4.tif"

Running this script in the shell should give you the same output as Qgis.

Another of the tools is one created by the author of the GDAL library, it is called FWtools, it can be downloaded from here:
http://fwtools.maptools.org/

Once installed, follow the instructions below to appreciate the potential of the tool and the respective library:
https://trac.osgeo.org/gdal/wiki/UserDocs/RasterProcTutorial

To do this you have to download a file called "Workshop", it provides some files that are required by the tutorial.

Something that should be clarified is that the windows command console does not recognize the gdal commands by itself so that it recognizes gdal commands as FWtools does, you have to Run the following "setfw" batch file located in the directory where the FWtools was installed.

In addition, when installing the FWtools program, a program called OpenEV is also installed that allows, among other things, to open georeferenced files.

### Shapefile

The ESRI Shapefile (SHP) format is a proprietary spatial data computer file format developed by the company ESRI, whose purpose is the exchange of geographic information between Geographic Information Systems.
A shapefile is a vector digital storage format where the location of geographic elements and the attributes associated with them are stored. However, it lacks the capacity to store topological information. It is a multi-file format, that is, it is generated by several computer files. The minimum number required is three and they have the following extensions:
• .shp - is the file that stores the geometric entities of the objects.
• .shx - is the file that stores the index of geometric entities.
• .dbf - is the database, in dBASE format, where the information on the attributes of the objects is stored.

The first thing we did was create a polygon Shapefile in Python. To later take up the polygon created by the project of the previous interns and pass the code to C++ to be executed together.

1) This test program consists of one polygon inside another. The Shapefile is named test and is saved to a folder that is specified in the code. If it exists, it is deleted and recreated. The code is the following:

[Show](README.md) script or [download](Test.cpp)

This file that we call Polygon written in Python that is located inside the local drive C is executed in the console.

![image](https://user-images.githubusercontent.com/105976212/219904713-27e6250c-0dd9-4676-86ff-6af097d79786.png)

And then the file test.shp is opened, which was created in the folder TO RUN THINGS, using the QGIS program, demonstrating that it has achieved what was proposed with their respective coordinates:

![image](https://user-images.githubusercontent.com/105976212/219904732-be62c2da-6025-447f-9d86-efd0db3a0a58.png)

2) The following python code is executed on the command line, it is saved in the file called poligono2 on local disk c.

[Show](README.md) script or [download](Poligono2.py)

![image](https://user-images.githubusercontent.com/105976212/219904752-bb7d22be-cc47-4d09-b1b0-232af676c6ef.png)

The image to polygonize is the following:

![image](https://user-images.githubusercontent.com/105976212/219904767-db7bc093-ec21-417d-ac4f-3da212ebd84b.png)

Then the test.shp file was opened in QGis as a result of the code execution, which was saved on the local drive c. The result was the following:

![image](https://user-images.githubusercontent.com/105976212/219904789-856cd827-b964-44a8-bebe-422b3d3f6598.png)

3) The following code should be added to the work carried out by the previous fellows, to save the final image obtained after the generation of polygons and binarization, to transform said image to shapefile.

bool QImage::loadFromData ( const uchar * data, int len, const char * format = 0 )

That function loads an image from the file with the given filename . Returns true if the image was loaded successfully, false otherwise.

The loader attempts to read the image using the specified format, eg PNG or JPG. If the format is not specified (which is the default), the loader polls the header file to guess the file format. In our case the image is TIF type. The file name can refer either to an actual file on disk or to one of the application's built-in resources.

## 📌 Conclusion and future work and research

Our program is the continuation of the implementation of the analysis of aerial images to detect these areas of weeds.

The objective is to reduce the amounts of agrochemicals applied in crop fields, for a more environmentally friendly treatment of the land. The application of herbicides is carried out on the entire surface, even when it is necessary only in specific areas.

This treatment would be applied exclusively on the surfaces that contain weeds, and the rest would be sprayed in smaller quantities, and this entails a significant saving of herbicides and consequently reduces environmental contamination due to its controlled use.

With the developed application, the georeferencing of the aerial image was solved, the creation of a vector that contains the polygons that enclose the undergrowth and the generation of a shapefile file.

The georeferencing of the image is assisted by the user, indicating the coordinates of several points, so that the geographic information of the image is generated. (geoTIFF format).

The generation of the Shapefile consists of a digital storage vector format where the location of the geographic elements and the attributes associated with them are stored. It is done through the geographic information of the image and the vector that contains the polygons.

The sprayer interprets this format and therefore it is the final file that is needed, since it will make up the prescription map, for the variable application of pesticide.

For a total development, which allows its real implementation, the following implementations are necessary:

- This application successfully achieves the main objective, but it must be passed to C++ language to be able to be implemented with the code of the previous group of interns, since the algorithms achieved are in python language.

- Conversion from pixel to meter. Currently, the program filters the image noise through a variable structural element (in pixels). Thus, minor patches of weeds are not considered. For it to make sense, it needs to be specified in meters, so the image must have spatial information (georeferencing).

- Expansion of Polygons. Once you have the spatial information in the image, you have to take into account the width of the boom of the machine (pesticide applicator) because it can be from 10 to 25 meters, and therefore smaller polygons should be included along with others. bigger ones because they will have an application anyway.

- In OpenCV, images by default are stored in the BGR order and we will work in RGB. There are many color models. Some are better for certain applications, not all are complete. RGB is the one that best fits the capture mode (color filters) and generation (monitor pixels) in digital image. RGB is more widely used, based on an additive mixing model, with 3 primary colors: R-red, G-green, B-blue. The additive combination of these primary colors produces the full range of colors that can be represented in RGB.


With all the documentation that is presented, the program codes and the reference links, another group would be able to relieve the project and complete and/or improve it, achieving continuity between the research carried out at INTA and the Digital III chair, to generate an application with specific practical purposes.

  ## Author
**Bárbara Ángeles Ortiz**

 <img src="https://avatars.githubusercontent.com/u/105976212?v=4" width=115><br><sub></sub>

[LinkedIn](https://www.linkedin.com/in/barbaraangelesortiz/) | [GitHub](https://github.com/BarbaraAngelesOrtiz)

![Status](https://img.shields.io/badge/status-finished-brightgreen)

![Python](https://img.shields.io/badge/python-3.10-blue)


