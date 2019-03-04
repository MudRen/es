#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "do_plast", "plast" );
}
 
void create()
{
        set_name( "fragment", "镜子的碎片" );
        add( "id", ({ "fragment" }) );
        set_short( "镜子的碎片" );
        set_long( @C_LONG
这是一片镜子的碎片，反映著你一张充满疑惑的脸。你可以试著把它贴回(plast)原处。
C_LONG
                );
                set("unit","片");
                set("weight", 10);
                set("value",({ 5, "silver"}) );
        set("no_sale", 1 );
}
 
int do_plast(string arg)
{
    if( !arg || arg != "mirror" ) {
        tell_object(this_player(),
                "你想把这碎片贴在那儿？。\n" );
        return 0;}
    if ((string)environment(this_player())->query("short")=="李□的收藏室" &&
        this_player()->query_temp("look_mirror")) {
        tell_object(this_player(),
                "你把碎片贴回镜上的角落，镜子发出一阵温暖的光茫。\n" );
        this_player()->set_temp("mirror_ok",1);
        remove();
        } else
        tell_object(this_player(),
                "这儿没有镜子啊...\n" );
        return 1;
}
