#include <mudlib.h>

inherit MONSTER;

void create ()
{
       ::create();
       set_level(13);
       set_name( "silver mollusk", "银线蛞蝓");
       add( "id", ({ "mollusk" }) );
       set_short( "银线蛞蝓");
       set("unit","只");
       set_long(@LONG
一只硕大无朋的陆生蛞蝓。两道亮银线由头部中心开始平行的划过略带粉红而透明的
躯干一直到尾部，爬过的地方都覆盖上一条似由冰霜结成的白色粉状痕迹，看它悠闲
的在你面前爬来爬去，让你忍不住就想做弄它一番。
LONG    );
       set_skill("dodge",90);
       set_natural_weapon(45,5,10);
       set_natural_armor(10,40);
       set_c_verbs(({
         "%s缓缓的靠向%s",
         "%s黏住了%s",
         "%s贴上了%s",
         "%s吐出透明的分泌物沾住了%s",
         "%s爬过%s",
         }));
       set_c_limbs(({"腹部","头部","尾部"}));
}
