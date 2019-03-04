#include "../moyada.h"

inherit ARMOR;

void create()
{
	set_name( "dirty shirt", "脏衬衫" );
	add( "id", ({ "shirt", }) );
	set_short("脏衬衫");
	set_long( @C_LONG
    一件用普通的布织成的衬衫, 又脏又臭, 不知多久没洗了。
C_LONG
	);
	set( "unit", "件" );
        set( "weight", 50 );
	set( "type", "body" );
	set( "material", "cloth");
	set( "armor_class", 5 );
	set( "value", ({ 10, "silver" }) );
}
