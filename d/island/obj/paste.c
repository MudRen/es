#include "../island.h"

inherit IOBJ+"drink.c";

void create()
{
    ::create();
    set_name("Loquat paste","��ͩ�󴨱����˸�");
    set("id", ({ "paste","herb" }) ) ;
    set_short("��ͩ�󴨱����˸�");
    set_long(@C_LONG
������ͩ�������ļ�Ʒ���˸࣬ר�κ���ɳ��Ŷ����
C_LONG
             );    
    set("container",0) ;
    set("tp",100);
    set("value",({ 10,"gold" }) ) ;
    set("amount",0) ;
    set("c_succ","����ҹɱ¾����񺰽У������⴨�����˸�֮�ᣬʹ����ú����ö��ˡ�\n") ;
    set("c_osucc","$CN����һƿ�������˸�֮�ᣬ�ְ�ƿ�Ӹ�������ȥ���㿴�ö�ɵ���ˡ�\n") ;
}
