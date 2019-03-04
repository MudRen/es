#include <mudlib.h>
inherit OBJECT;
 
void init()
{
        add_action( "hold_mark", "hold" );
}
 
void create()
{
        set_name( "army mark", "步卒兵符" );
        add( "id", ({ "army","mark" }) );
        set_short( "步卒兵符" );
        set_long( @C_LONG
这是一面金制的令牌，上面刻著『牧马关步兵令』，据说这兵符和步兵团长有同等
的地位，拿著(hold)它可以通过所有的守卫和士兵。当然，前提是他们对你没有私
人恩怨...
C_LONG
                );
                set("unit","面");
                set("weight", 10);
                set("value",({10, "silver"}) );
        set("no_sale", 1 );
}
 
int hold_mark(string arg)
{
    if( !arg || arg != "mark" ) return 0;
    if ((string)environment(this_player())->query("short")=="库房大门" ) {
        tell_object(this_player(),
                "你拿著令牌，守卫对你一幅必恭必敬的样子。\n" );
        this_player()->set_temp("army_mark",1);
        this_player()->set_explore("eastland#26");
        } else
        tell_object(this_player(),
                "你拿著令牌像笨蛋一样晃呀晃呀地，可是没人理你。\n" );
        return 1;
}
