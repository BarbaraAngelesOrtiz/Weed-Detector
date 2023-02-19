# script to add a point to a new shapefile
# import modules and set the working directory
import ogr, os, sys
os.chdir('c:/PARA EJECUTAR COSAS')

# get the driver
driver = ogr.GetDriverByName('ESRI Shapefile')

# create a new data source and layer
if os.path.exists('test.shp'):
	driver.DeleteDataSource('test.shp') 
ds = driver.CreateDataSource('test.shp')
if ds is None:
	print 'Could not create file'
	sys.exit(1)
layer = ds.CreateLayer('test', geom_type=ogr.wkbPolygon)

# add an id field to the output
fieldDefn = ogr.FieldDefn('id', ogr.OFTInteger)
layer.CreateField(fieldDefn)

# create a new line object
ring = ogr.Geometry(ogr.wkbLinearRing)
ring.AddPoint (0,0)
ring.AddPoint (100,0)
ring.AddPoint (100,100)
ring.AddPoint (0,100)

ring.CloseRings()
ring.AddPoint(0,0)

outring=ogr.Geometry(ogr.wkbLinearRing)
outring.AddPoint(0,0)
outring.AddPoint(100,0)
outring.AddPoint(100,100)
outring.AddPoint(0,100)
outring.AddPoint(0,0)

inring=ogr.Geometry(ogr.wkbLinearRing)
inring.AddPoint(25,25)
inring.AddPoint(75,25)
inring.AddPoint(75,75)
inring.AddPoint(25,75)
inring.CloseRings()

polygon=ogr.Geometry(ogr.wkbPolygon)
polygon.AddGeometry(outring)
polygon.AddGeometry(inring)

print polygon.GetPointCount ()
outring=polygon.GetGeometryRef(0)
inring=polygon.GetGeometryRef(1)

# get the FeatureDefn for the output layer
featureDefn = layer.GetLayerDefn() 

# create a new feature
feature = ogr.Feature(featureDefn)
feature.SetGeometry(polygon)
feature.SetField('id', 1)

# add the feature to the output layer
layer.CreateFeature(feature)
print 'Could create file'
