
#include "mudlib.h"

inherit MONSTER;

void create ()
{
       ::create();
       set_level(4);
       set_name( "deer", "¹" );
       set_short("¹");
       set("unit","ֻ");
       set_long(@C_LONG
�㿴��һֻ�ɰ��Ķ�����ڲ�ԭ������ɢ������������һ��Ư
���ĳ��ǣ�����������ѱ�����ӣ�һ�㶼�����ˡ�
C_LONG
                        );
       set_perm_stat("dex", 10);
        set_natural_armor( 25, 6 );
        set_natural_weapon( 8, 4, 7 );
       set ("armor_class", 20);
       set_c_verbs(({"%s������������%s��ȥ","%s�����Ľ���%sײȥ"}));
       set_c_limbs(({"����","����","�Ų�","ͷ��"}));
#include <replace_mob.h>
}
