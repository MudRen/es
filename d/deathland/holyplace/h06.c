
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","����������Ʈ�촦");
  set_long(@Long
Long
,@CLong
һ�������ĵ�������,�Ĵ��ĺ�Ӱ������Ϣ��������Ϯ����.����ļž����˸е�����,
���㲻��������Ҫ����һЩ����.û�з���,û��ˮ��,�������޷������Լ��ĽŲ���,�㲻
�������Լ�����һ�����޵ĵط�.�Һ��㷢����Ķ�����һ���������Ĺ�Դ������.
CLong
);

set("exits",([
             "west":Deathland"/holyplace/h07",
             "east":Deathland"/holyplace/h05",
             ]));
reset();
}
