namespace cbr {
    template <typename T>
    class ItemRec {
        virtual void AddData(const T& data) {}
        virtual void SetConfig(const std::vector<std::pair<std::string, std::string>>& config) {}
        virtual void Build(std::string policy) {}
        virtual void GetRankingList(int id, int k, std::vector<int>& result) {}
        virtual void GetRankingList(int id, int k, std::vector<std::pair<int, double>>& result) {}
    };    
}
