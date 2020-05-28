// fieldtype is TMemoField
// if your query don't have fields added
TStream *stream = NULL;
try
{
	mstream = query->CreateBlobStream(query->FieldByName("YourTextField"), bmRead);
	Memo1->Lines->LoadFromStream(stream);
}
__finally
{
	if (stream != NULL)
		delete stream;
}

// To encapsulate it and use it on all your application

void __fastcall LoadStreamIntoStrings(TStrings *strings, TField *field)
{
	TStream *stream = NULL;
	try
	{
		stream = field->DataSet->CreateBlobStream(field, bmRead);
		strings->LoadFromStream(stream);
	}
	__finally
	{
		if (stream != NULL)
			delete stream;
	}
}

// And call this way

LoadStreamIntoStrings(Memo1->Lines, query->FieldByName("YourTextField"));