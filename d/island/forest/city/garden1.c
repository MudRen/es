#include "../tsunami.h"
#include "/include/move.h"
inherit ROOM;

void create()
{
    ::create();
    set_short("����԰");
    set_long(@LONG
������������������Ϊ��������԰�����������˸����ѵ�һ�����滨��
�ݣ��硸 ����֮�᡹(tear_flower)���� ʤ��Ů�� ��(goddess_flower)
�ȵȣ��Ա߻�����һЩ����(tree)�������������������Եļ����ڳ������
ͬ����Ʒ�֣�ֻ������û����󣻲������������������������������ѽ��
LONG
            );
    set("light",1);
    set_outside("island");
    set("exits",([
        "south":CITY"inway1"]) );
    set("item_desc",([
        "tear_flower":@ALONG
����һ������ʮ�ֺ����Ļ��ܣ��ڹ�ħ��۹�ʱ�������ֻ��洦�ɼ�����
�Դ��Ǵ���ʯ�����ᣬ���ֻ����������ˣ����ֻ��Ļ����ǡ����ˣ����
�����������Ϊ�˼�������ս����������ͬ����
ALONG
       ,"goddess_flower":@BLONG
����ħ���������ս��ʱ�ش��Ļ��䣬�ഫ���ɱ�������İ�ȫ��Ҳ��
Ϊս������ʤ����������һ֧����Ǩ��ʱ��Ϊ������ƽ��������Ҳ��������
�������������                     
BLONG
        ,"tree":@CLONG
�ס�������Щ���ѵ�Ҳ�����ҵ��ػ��������ῴ����������ͬһƷ���أ�
CLONG
            ]) );
    set("objects",([
        "farmer":TMOB"farmer1",
        "luoky":TMOB"luoky"]) );
    reset();
#include <replace_room.h>
}

