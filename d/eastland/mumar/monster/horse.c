#include <../mumar.h>
inherit MONSTER;
inherit MOUNT;
 
void create()
{
        ::create();
        set_level(17);
        set_name( "fight horse", "战马" );
        add( "id", ({ "horse" }) );
        set_short( "战马" );
        set_long(
        "这是一匹高大、强壮、雄伟的红色牧马关战马，你站在旁边觉得自己矮了一截。\n"
        "你觉得若能骑(mount) 著它在战场上奔驰，一定是人生一大乐事。\n");
        set( "unit", "匹" );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 15 );
        set_perm_stat( "con", 25 );
        set_perm_stat( "kar", 25 );
        set_natural_weapon( 45,40,60 );
        set_natural_armor( 76,39 );
        set_skill("dodge",80);
        set( "alignment", 300 );
        set( "extra_look","$N正骑著一匹火红的牧马关战马，看起来一付很威风的样子。\n");
        set( "mountable", 1);
        set( "max_load", 2300 );
        set_c_limbs( ({ "头部", "身体", "後腿", "尾巴" }) );
        set_c_verbs( ({ "%s抬起後腿，往%s一踢", "%s人立起来，用前肢在%s一阵乱踩"}) );
        equip_armor(OBJS"saddle");
}
void init()
{
        mount::init();
}
