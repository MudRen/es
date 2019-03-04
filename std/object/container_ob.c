//#pragma save_binary

inherit "std/object/ob_logic";
#include "/std/object/prop.c"

int receive_object(object ob)
{
	int weight ;

	weight = ob->query("weight") ;
	if ( weight + this_object()->query("load") > 
		this_object()->query("max_load") ) 
		return 0;
	this_object()->add("load",weight);
	return 1;
}
int release_object(object ob)
{
	this_object()->add("load",-ob->query("weight"));
	return 1;
}
 
