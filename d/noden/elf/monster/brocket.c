#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(2);
       set_name( "brocket", "С¹" );
        set_short( "С¹" );
       set("unit","ֻ");
        set_long(
       "�㿴��һֻ�ɰ��Ķ�����ڲ�ԭ������ɢ������������һ��Ư\n"
       "����С�ǣ�����������ѱ�����ӡ�\n"
                        );
       set_perm_stat("dex", 5);
       set ("weapon_class1", 10);
       set ("armor_class", 10);
       set_c_verbs(({"%s������������%s��ȥ","%s�����Ľ���%sײȥ"}));
       set_c_limbs(({"����","����","�Ų�","ͷ��"}));
}
