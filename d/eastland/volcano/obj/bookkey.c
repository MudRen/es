#include "../oldcat.h"

inherit OBJECT;

void create()
{
        set_name("stone key", "蓝宝石钥匙");
        set_short("蓝宝石钥匙");
        set_long( @LONG
    一支由漂亮蓝宝石打制成的钥匙。你可以用它直接  < insert 某地方 > 来开
启特定的东西。
LONG    );
        set( "unit", "支" );
        set( "weight", 20 );
        set( "value", ({ 50,"silver"}) );
        set("no_sale",1);
}

void init()
{
  add_action("do_unlock", "insert");
}

int do_unlock(string arg)
{
  object here,book;
  
  if (arg!="wall_hole")
    return notify_fail("你试了半天，一点结果也没有。\n");
  if (!this_player()->query_temp("can_insert_key"))
         return 0;
  here=environment(this_player());
  if (here->query("wall_box_for_mar_short"))
    if (present("wraith elder",here))
      return 
        notify_fail("你发现矮灵族长老正恶狠狠地盯著你，只好赶紧落荒而逃。\n");
    else   
      if (here->query("have_book")) {
        tell_object(this_player(),@LONG
你把蓝宝石钥匙插进墙上的暗洞，飕的一声，钥匙被吸了进去，并弹出一本小册
子。你顺手就把小册子接了起来。
LONG  );
        here->set("have_book",0);
        seteuid(getuid());
        book=new(OOBJ"sword_book1.c");
        book->move(this_player());
        this_object()->remove();
        return 1;
      }
      else {
        tell_object(this_player(),
          "你把蓝宝石钥匙插进墙上的暗洞，可是钥匙又弹了出来。\n"
          );
        return 1;     
      }
  return 0;      
}
