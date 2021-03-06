#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

int left_times=3;
void create()
{
        set_name("poison liquid","「文蛛」毒液");
        add( "id" , ({ "liquid" }) );
        set_short( "「文蛛」毒液");
        set_long(@C_LONG
一些由「文蛛」身上促摄取出来的毒液。据说，这毒液能解百毒，或许你可以喝喝
看(drink_liquid)以治你身上所中的毒。
C_LONG  );      
        set("unit","堆");
        set("weight",10);
        set("drink_liquid",1);
        set("no_sale",1);
        set("value", ({100, "silver"}) );
}
void init()
{
    add_action("do_drink","drink_liquid");
}
int do_drink(string arg)
{
    object player;
    player=this_player();
    left_times--;
    if( !player->query("conditions/simple_poison") ) {
       write("唉呀，你喝了毒液之後居然中毒了！\n");
       (CONDITION_PREFIX + "simple_poison")->apply_effect( player, 10 , 5 );
       return 1;
    }
    tell_object( player, 
       "你喝下「文蛛」毒液之後，由於以毒攻毒，瞬间令你所中的毒完全被解除了！\n");
    SIMPLE_POISON->remove_effect(player);
    player->add("hit_points",-10);
    if (left_times<0) {
       write("当你喝完这一口时，却发现已经没有剩下来的毒液了！\n");
       this_object()->remove();
    }
    return 1;
}