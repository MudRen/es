
#include "mudlib.h"

#define AC ({ 7,4,4,7,7,7 })
#define DB ({ 1,0,0,1,2,1 })
#define TYPES ({"head","arms","hands","legs","cloak","feet" })
#define UNITS ({"��","��","˫","˫","Ƭ","˫" })
#define ADD_CNAME ({"ɽ��ս��ͷ��","ɽ��ս������","ɽ��ս������","ɽ��ս���ּ�","ɽ��ս������","ɽ��ս��ѥ" })
#define EXTRA_ID ({"helmet","sleeves","bracers","leggings","backarmor","shoes" })
inherit ARMOR;

void create()
{
        int i;
        i = random(6);
        set_name("bandit "+EXTRA_ID[i], ADD_CNAME[i]);
        add( "id", ({ EXTRA_ID[i] }) );
        set_short(ADD_CNAME[i]);
        set_long(
                "������ɽ����ɽ������ʹ�õ�"+ADD_CNAME[i]+"\n"
                "��Ȼ�������Ǻ����ۣ�����ȴ�൱ʵ��..\n"
        );
        set("unit",UNITS[i]);
        set( "type", TYPES[i] );
        set( "material", "heavy_metal");
        set( "armor_class", AC[i] );
        set( "defense_bonus", DB[i] );
        set( "weight", 250 );
        set( "value", ({ 230, "silver" }) );
}



