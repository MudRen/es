
#include "iigima.h"
inherit ROOM;

void create()
{
       ::create();
       set_short("back","�����");
       set_long(@C_LONG
�������ȣ��������������񹬵��������в��ٵ���
�εȵȵģ���Ȼ���������������ԣ��㿴��ǰ���һ�ȹһ�
�л������Ǵ�����񣬵��ǿ����������Զ�ɣ��Ѿ�������
Щ�ҳ��������쾮��һЩ��ɫ�Ĵ���ʯ��̶��ɣ�ʹ����
�ܿ����й���������Ϣ��
C_LONG );
       set("exits",([
                     "northwest":"/d/noden/drow/r69",
                     "south":"/d/noden/drow/r67"
                    ]));
       set("light",1);
}

