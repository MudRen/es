
#include "mudlib.h"

inherit MONSTER;

void create ()
{
       ::create();
       set_level(3);
       set_name( "fox", "����" );
       set_short("����");
       set("unit","ֻ");
       set_long(@C_LONG
�㿴��һֻ�ɰ��ĺ��꣬�����ּ���ֵĵ���������������һ��Ư
�����˵��۾���������һ�㶼�����ˡ�
C_LONG
               );
       set_perm_stat("dex", 9);
        set_natural_armor( 16, 5 );
        set_natural_weapon( 4, 3, 6 );
       set_c_verbs(({"%s������������%s��ȥ","%s������������%sҧȥ"}));
       set_c_limbs(({"����","����","�Ų�","ͷ��"}));
#include <replace_mob.h>
}
