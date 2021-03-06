#include <mudlib.h>
#include "../legend.h"

inherit OBJECT;
int pl1,pl2;

void create()
{
        set( "extra_look", "$N正坐在一艘小船上");
        set_name("Oak oar", "橡木桨");
        add("id", ({ "oak oar","oar" }) );        
        set_short("橡木桨");
        set_long( @LONG
    一支橡木做的桨，看起来已经很旧了，但是还是很坚实耐用。你可以打
(help_me oak_oar)，如果你不知道怎麽划船的话。
LONG
        );
        pl2=random(5);
        set( "unit", "支" );
        set( "weight", 10 );
        set( "prevent_drop",1);
        set( "prevent_insert",1);
}

void init()
{
  add_action("help_me", "help_me");
  add_action("do_oar", "oar");
}

int do_oar(string arg)
{
    string c_dir,dest;

    if( !arg )
      return notify_fail( "你想要往哪边划呢？\n");
    switch(arg) {
      case "east"  :
           pl1=pl1+3;
           pl2=pl2+3;
           c_dir="东";
           break;
      case "west"  :
           pl1=pl1+2;
           pl2=pl2+5;
           c_dir="西";
           break;
      case "south" :
           pl1=pl1+5;
           pl2=pl2-2;
           c_dir="南";
           break;
      case "north" :
           pl1=0;pl2=random(5);
           c_dir="北";
           break;
      default :
      return notify_fail( "你想要往哪边划呢？\n");
    };
    tell_object(this_player(),sprintf("你努力的往%s边划去。\n",c_dir));
    tell_room(environment(this_player()),sprintf(
     "%s努力的向%s边划了过去。\n",this_player()->query("c_name"),c_dir),this_player());
    if ((pl2==13)||(pl2==19)||(pl2==31)||(pl2==37)) {
      pl2=pl1=0;
      this_player()->move_player(LAKE"lake05","SNEAK");
      tell_room(environment(this_player()),sprintf(
        "%s摇著桨，慢慢地划了过来。\n",this_player()->query("c_name")),this_player());
      return 1;
    }
    dest=LAKE"l_maze"+(string)((pl1 % 7));
    this_player()->move_player(dest,"SNEAK");
    tell_room(environment(this_player()),sprintf(
        "%s摇著桨，慢慢地划了过来。\n",this_player()->query("c_name")),this_player());
    pl1=(pl1>100)?0:pl1;
    if ((pl2<-1)||(pl2>40)) pl2=random(5);
    return 1;
}

int help_me(string arg)
{
  if( !arg || arg!="oak_oar" ) return 0;
  tell_object(this_player(),@LONG
   你突然发现你不会划船，不论你怎麽使力，船只是不停地在原地打转。
   无计可施之下，你只好大声呼  
            救......救        命        呀！！！
   
   一只小白鱼游出水面，用著鄙夷的眼光看著你，并说道
   没看过这麽差的，不会划船也遨游大海。我就好心教你一下吧，注意听啊: 
   你可以划向--某个方向  (oar direction) ，例如< oar east >。这里是
   大海，你随便划任何方向  (east south west north)都不会撞壁啦。
   
   小白鱼说完就一头溜进水里去了。 


LONG    
    );
      return 1; 
}       
