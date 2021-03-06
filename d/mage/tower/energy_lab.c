//#pragma save_binary

#include "../mage.h"

inherit ROOM;
void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "The Energy Room", "能源室" );
	set_long( @LONG
  NEED WORK HERE!
LONG
            , @C_LONG
这是储存魔法能源的地方，你感到一股强大的魔力。在这里可以请专人帮
你补充(recharge)魔法武器的能源，不过切记勿自己动手，小心控制不当毁了
装备。
C_LONG
);
	set( "exits", ([ "down" : MAGE"library", ]) );
    set( "no_monster", 1);
	set( "objects", ([
	 "cid" : MAGE"monsters/cid", 
         "wand" : MAGE"weapons/little_wand",
	]) );
	reset();
}

void init()
{
    add_action("to_recharge", "recharge");
}

int to_recharge(string str)
{
    object item, who;
    int wc, damage, times, skill, karma, cost_money, cost_exp, money, exp;
    who = this_player();
    
    if( !str ) 
      return notify_fail( 
        "使用格式: recharge <物品名称> \n" );
    if( !(item=present(str, who)) )
      return notify_fail("你身上没这个东西。\n" );
    if( !item->query("max_charge") )
      return notify_fail( "这不是魔法物品，无法补充魔法能源!\n" );
    wc = (int)item->query("weapon_class");
    damage = (int)item->query("special_damage");
    times = (int)(item->query("max_charge"))-(int)(item->query("charge_left"));
    if( !times ) 
      return notify_fail("这物品已充满了魔法能源，你还要浪费钱吗?\n");
    skill = (int)who->query_skill("recharge");
    karma = (int)who->query_stat("karma");
    money = 200;
    exp = 500;
    cost_money = wc*damage*times*(150-skill)/money;
    cost_exp = wc*damage*damage*(130-skill)/exp;
    if( (int)who->query_exp_stock() < cost_exp )
      return notify_fail(sprintf("补充这物品的能源将损失你 %d 点经验值，你可用经验值不足。\n",cost_exp));
    if( present("cid") && !who->debit( "silver", cost_money ) )
      return notify_fail(sprintf("补充这物品的能源需要 %d 银币。\n" ,cost_money));
    who->gain_experience( -cost_exp );
    if( !present( "cid" ) ) {
      tell_room( this_object(), sprintf( "%s把%s放入能源补充机里面。\n",who->query("c_name"),item->query("c_name")), who );
      tell_object( who, sprintf("你小心翼翼的把%s放入能源补充机里面。\n",item->query("c_name")));
      if( random(125) > skill || random(30) > karma ) {
        tell_room( this_object(), sprintf("但是一不小心%s化成灰烬消失了。\n",item->query("c_name")));
        item->remove();
      } else {
        tell_object( who, 
          sprintf("一段时间之後，你把%s拿了出来，它看起来充满了魔法能源。\n" ,
	item->query("c_name")));
        tell_room( this_object(), 
          sprintf("一段时间之後，%s把%s拿了出来，它看起来充满了魔法能源。\n" ,
	who->query("c_name"),item->query("c_name")), who);
        item->set("charge_left",(int)item->query("max_charge") );
      }
    } else {
      tell_object( who, 
        sprintf("你把%s交给施得，只见他把它放入能源补充机中。\n一段时间之後，他把它拿了出来并归还给你。\n" ,item->query("c_name")));
      tell_room( this_object(), 
      sprintf("%s把%s交给施得，只见他把它放入能源补充机中。\n一段时间之後，他把它拿了出来并归还给%s。\n" ,
	who->query("c_name"),item->query("c_name"),who->query("c_name")),who );
      item->set("charge_left",(int)item->query("max_charge") );
      tell_room( this_object(), "施得说: 充好了。\n");  
    }
    return 1;
}
