#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name( "red sleeve blade", "红袖刀" );
        add( "id", ({ "blade","red sleeve blade" }) );
        set_short( "红袖刀" );
        set_long(@LONG
这是一把让人一见锺情的刀。刀锋是透明的，刀身绯红，刀光漾映，像透明的玻璃
镶裹著绯红色的骨脊。刀略短，刀弯处如绝代佳人的纤腰，挥动时带著一种音赖似
的清吟，还掠起微微的香气。这就是名闻江湖的～  红袖刀  ～。
LONG);

        set( "unit", "把" );
        set( "type", "longblade" );
        set( "weight", 70 );
        set( "weapon_class", 35 );
        set( "min_damage", 25 );
        set( "max_damage", 40 );
        set( "value", ({ 720, "gold" }) );
        set_c_verbs( ({
           "手执%s，身形一掠，刀锋在空中划出一道长虹斩向%s",
           "运劲一震%s，刀身发出一声清吟，\n一式【黄莺出谷】，～～刀锋直取%s",
           "使出乱披风刀法，%s狠狠的挥向%s",
           "攻势一变，%s刀身暴炽，四周空气变得燥热，\n无数的刀影伴著如烈焱一般的内劲卷向%s",
           "使出【运转七星】，只见%s刀光点点，瞬间罩住了%s",
           "刀法一缓，%s如凿刻般的砍向%s",
           "倒转%s，刀柄直扣%s",
           "刀势一变，倏地，%s刀身上结了一层薄霜，四周气温骤降，\n一道阴寒的刀劲攻向%s",
        }) );
}
