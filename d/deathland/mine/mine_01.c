
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("direction","south");
  set_short("The Entrance of Drawf mine","���˿�ӵ����");
  set_long(@Long
Long
,@CLong
�Թ������˶�춽��Ӿ���һ�����������,���������ܹ������κβ��ڵ�
�������һ�����,���Խ��Ӷ�춰����ƺ�û�ж���������. ������һ�ֿ�
��,Mithril ��,������������߲��ɻ�ȱ�Ľ���,��������ս��״̬�İ�����
��˵,�����Ե��ر����Ҫ��.�����ǰ��˿�ӵ����.�������ṩ���˲��ɻ�
ȱ�Ľ��� Mithril ��\��\������������Ļƽ�.
�ڵ���������������.ר���˿�ͨ��ʹ��.���ܿ���\��\���˿���������.����
�����ڵع�����.����һֱ���쵽�ص��,ͨ��δ֪������,���������һ����
�����ߵ�һ������.
CLong
);
set("exits",([
//             "east":Deathland"/mine/factory",
             "north":Deathland"/city/c6",
             "south":Deathland"/mine/mine_02"
             ]));
#include <replace_room.h>
}
