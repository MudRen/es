#include <mudlib.h>
#include "../../story.h"
inherit SPALACE"sacrifice";

void create()
{
    ::create();
    set_short( "plate", "����̨" );
    set_long(@C_LONG
�����Ƿ���̨������������԰���Ҫ�Ķ������׸���ۣ����������Ĺ��Ļ�
����ۻ��ʹ͸���һЩǮ��
C_LONG
    );
    set("light",1);
    reset();
}