
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "golden dagger","镀金扁钻" );
        add( "id",({ "dagger","daggercheck" }) );
        set_short( "镀金扁钻" );
        set_long(@C_LONG
这是钱形次郎专用的扁钻，听说钱形次郎每杀一个人，就会在扁钻上镶朵
金色的樱花，现在扁钻的握柄已经镶满金色的花朵，实在太血腥了。不过
自从钱形次郎退出江湖以後，这把扁钻就久不现江湖，想不到在今天又被
你给碰上了............仔细一看，上面的金色花朵竟然是假的
C_LONG
        );
        set( "unit", "把");
        set( "weapon_class", 30);
        set( "type", "dagger" );
	set( "min_damage", 15 );
	set( "max_damage", 30 );
        set( "weight", 40 );
        set( "value", ({ 150, "gold" }) );
        set( "second" , 0 );
}

