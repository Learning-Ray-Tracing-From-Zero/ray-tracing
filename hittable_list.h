#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <memory>// ����ָ�� std::shared_ptr
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
public:
	hittable_list();
	hittable_list(shared_ptr<hittable> object);

	void clear();
	void add(shared_ptr<hittable> object);

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
	std::vector<shared_ptr<hittable>> objects;
};

#endif

/*
* shared_ptr ����ָ��
* shared_ptr ������һ�����󣬸ö���ʹ�����ü�����������Դ
* shared_ptr ������Ч����һ��ָ����ӵ�е���Դ��ָ�����һ�� null ָ��
* ��Դ���ɶ�� shared_ptr ����ӵ�У���ӵ���ض���Դ�����һ�� shared_ptr �������ٺ���Դ���ͷ�
* shared_ptr���·����������Դʱ��ֹͣӵ����Դ��
*
* ����ָ��������һ���ո��·�����ڴ����������ʼ��
*
* make_shared<thing>(thing_constructor_params ...) Ϊָ�������ͷ���һ���ڴ�,
* ʹ����ָ���Ĺ��캯������������������, ������һ������ָ�� shared_ptr<thing>
*
* �ڴ�����ʹ������ָ���Ŀ����Ϊ�����ö������ͼԪ����һ��ʵ��
* (�ٸ�����, һ�Ѳ�ͬ����ʹ��ͬһ���������), ���������ڴ���������ͨ��ָ����ӵļ򵥷���
*/
