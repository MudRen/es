
#include "mudlib.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(3);
        set_name( "little Taoist", "С����" );
        add ("id",({ "taoist","doshu","boy"}));
        set_short("С����");
        set("unit","λ");
        set_long(
@C_LONG
����һ���߰����ĺ��ӣ���Ȼ����һ�������������Ȼ������ʮ�㣬
һ��ʲ�ᶼ���������ӣ�����������ʦ�����������ſ��к����ˡ�
C_LONG
);
        set("alignment",150);
        set("wealth/silver",15);
        set_perm_stat("str",7);
        set_perm_stat("dex",7);
        set_perm_stat("kar",6); 
        set_natural_weapon(4,3,5);
        set ("natural_armor_class", 20);
        set_skill("dodge",35);
        set("natural_defense_bonus",2);
        set ("gender", "male");
        set ("race", "human");
        set_c_verbs(({"%s��˫����%s��ץ",
                      "%s�ö̽���%s����",
                      "%s��ͷ��%sʹ����ײȥ"}));
       
#include <replace_mob.h>
}
