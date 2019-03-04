#include <mudlib.h>
inherit OBJECT;

void create()
{
        set_name("hint", "小锦囊");
        set_short("hint", "小锦囊");
        set_long(@CLONG
这是一个包的很漂亮的信封，也许你可以把它打开来读里面的内容
CLONG
        );
        set("id", ({"hint"}));
        set("unit", "个");
        set( "weight", 1 );
        set( "value", ({ 1, "silver" }) );
        set( "no_sale", 1);
        seteuid( getuid() );
}
void init()
{
        set("owner",environment(this_object()));
        add_action( "do_open", "open");
        add_action( "do_read", "read");
}
int do_open(string str)
{

        if (!str || str != "hint" ) 
                return notify_fail(
                        "把什麽东西打开?\n");
        
        tell_object( this_player(), "现在好像还不是把锦囊打开的时候。\n" );
        return 1;

}
int do_read(string str)
{
if (!str || str != "hint" )
                return notify_fail(
                  "读什麽?\n");
                                        
                 tell_object( this_player(), "你应该先打开锦囊...\n" );
                 return 1;
}

