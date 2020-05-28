// if you want to load the string from a TMemoField, you can do it two ways

// when you have a fields added in your dataset, you can use it directly
TMemoryStream *mstream = new TMemoryStream();
try
{
	queryTexto->SaveToStream(mstream);
	Memo1->Lines->LoadFromStream(mstream);
}
__finally
{
	delete mstream;
}

// if your query don't have fields added
TStream *stream = NULL;
try
{
	mstream = query->CreateBlobStream(query->FieldByName("Texto"), bmRead);
	Memo1->Lines->LoadFromStream(stream);
}
__finally
{
	if (stream != NULL)
		delete stream;
}