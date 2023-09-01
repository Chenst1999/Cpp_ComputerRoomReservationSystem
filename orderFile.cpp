#include"orderFile.h"

OrderFile::OrderFile() {
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string data;
	string interval;
	string stuID;
	string stuName;
	string roomID;
	string status;
	this->m_size = 0;
	while (ifs >> data && ifs >> interval && ifs >> stuID && 
		ifs >> stuName && ifs >> roomID && ifs >> status) {
		/*cout << data << endl;
		cout << interval << endl;
		cout << stuID << endl;
		cout << stuName << endl;
		cout << roomID << endl;
		cout << status << endl;
		cout << endl;*/
		//data:1
		string key;
		string value;
		map<string, string>m;
		int pos = data.find(":");
		if (pos != -1) {
			key = data.substr(0, pos);//第一个参数为起始截取位，第二个参数pos为截取多少位
			value = data.substr(pos + 1, data.size() - pos - 1);
			m.insert(make_pair(key,value));
		}
		pos = interval.find(":");
		if (pos != -1) {
			key = interval.substr(0, pos);//第一个参数为起始截取位，第二个参数pos为截取多少位
			value = interval.substr(pos + 1, interval.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuID.find(":");
		if (pos != -1) {
			key = stuID.substr(0, pos);//第一个参数为起始截取位，第二个参数pos为截取多少位
			value = stuID.substr(pos + 1, stuID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = stuName.find(":");
		if (pos != -1) {
			key = stuName.substr(0, pos);//第一个参数为起始截取位，第二个参数pos为截取多少位
			value = stuName.substr(pos + 1, stuName.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = roomID.find(":");
		if (pos != -1) {
			key = roomID.substr(0, pos);//第一个参数为起始截取位，第二个参数pos为截取多少位
			value = roomID.substr(pos + 1, roomID.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		pos = status.find(":");
		if (pos != -1) {
			key = status.substr(0, pos);//第一个参数为起始截取位，第二个参数pos为截取多少位
			value = status.substr(pos + 1, status.size() - pos - 1);
			m.insert(make_pair(key, value));
		}
		this->m_orderData.insert(make_pair(this->m_size, m));
		this->m_size++;
	}
	ifs.close();
	/*for (map<int, map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++) {
		cout << "key:" << it->first << "	value:" << endl;
		for (map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++) {
			cout << mit->first << " " << mit->second << " ";
		}
		cout << endl;
	}*/
}
void OrderFile::updataOrder() {
	if (this->m_size == 0) {
		return;
	}
	ofstream ofs(ORDER_FILE, ios::out | ios::trunc);
	for (int i = 0; i < this->m_size; i++) {
		ofs << "data:" << this->m_orderData[i]["data"] << " ";
		ofs << "interval:" << this->m_orderData[i]["interval"] << " ";
		ofs << "stuID:" << this->m_orderData[i]["stuID"] << " ";
		ofs << "stuName:" << this->m_orderData[i]["stuName"] << " ";
		ofs << "roomID:" << this->m_orderData[i]["roomID"] << " ";
		ofs << "status:" << this->m_orderData[i]["status"] << endl;
	}
	ofs.close();
}