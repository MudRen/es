#include <mudlib.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
        set_name("chi-eu's corpse","「蚩尤」的□体");
        add( "id" , ({ "corpse" }) );
        set_short( "「蚩尤」的□体");
        set_long(@C_LONG
这是「蚩尤」的□体。当时黄帝和蚩尤大战，蚩尤战败後□体就被埋在解池旁，多
年来，不乏巨人族的勇士想要来此盗□却都被中了沿途的埋伏，多年以後就不了了
之。
C_LONG  );      
        set("unit","具");
        set("weight",500);
        set("no_sale",1);
        set("chicorpse",1);
        set("value", ({1, "silver"}) );
}
