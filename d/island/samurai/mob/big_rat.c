#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(7);
        set_name( "big rat","������" );
        add ("id", ({ "rat"}) );
        set_short( "big rat","������");
        set("unit","ֻ");
        set_long(@ANGEL
����һ�������󣬿��������׶������
ANGEL
        );
        
        set ("gender", "male");
        set_c_verbs(({"%s��������צ��ץ��%s","%s����һת��β��˦��%s","%s����������ҧ��%s"}));
        set_c_limbs(({"����","ͷ��","�Ų�","β��"}));
}