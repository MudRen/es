#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(9);
        set_name("big snake", "巨蟒蛇");
        set_short("巨蟒蛇");
        set_long(
@C_LONG
这是一条凶猛巨大的大蟒蛇，看它肥胖的身躯，不知吞下多少东西！
C_LONG
        );
        set( "unit", "条" );
        set( "pursuing", 1 );
        set( "aggressive", 1 );
        set( "moving", 1 );
        set( "speed", 20 );
        set( "patrol", ({ "north","south"}) );
        set( "killer", 1 );
        set( "alignment", -400 );
        set( "natural_weapon_class1", 8 );
        set( "natural_min_damage1", 4 );
        set( "natural_max_damage1", 5 );
        set_c_limbs( ({ "头部", "肥肥的身体", "粗粗的尾巴" }) );
        set_c_verbs( ({ "%s用力扭动，往%s卷去" }) );
}

