#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(1);
       set_name( "rabbit", "����" );
        set_short( "����" );
       set("unit","ֻ");
        set_long(
       "�㿴��һֻ�ɰ��Ķ�����ڲ�ԭ��������Ծ����������һ˫\n"
       "�����Ķ��估��ֻͻ�����������˿����������㣬�޹��ı��������\n"
        "��Ƥ�ľ��������������ְ���\n"
                        );
       set_perm_stat("dex", 3);
       set ("weapon_class1", 3);
       set ("armor_class", 5);
       set_c_verbs(({"%s������������%s��ȥ"}));
       set_c_limbs(({"����","����","�Ų�","ͷ��"}));
}
