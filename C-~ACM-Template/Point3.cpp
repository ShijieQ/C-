struct point{
    long long  x, y, z;
    point(long long a, long long b, long long c):x(a), y(b), z(c){}
    point operator + (const point &other) const{
        return point(x+other.x, y+other.y, z+other.z);
    }
    point operator - (const point &other) const{
        return point(x-other.x, y-other.y, z-other.z);
    }
    point operator - () const{
        return point(-x, -y, -z);
    }
    point operator * (int p) const{
        return point(x*p, y*p, z*p);
    }
    bool operator == (const point &other) const{
        return x == other.x && y == other.y && z == other.z; 
    }
    // 两点对应的向量叉乘，即a × b;
    point operator * (const point &other) const{
        return point(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
    }
    // 两点对应的向量点乘，即a · b;
    long long dot(const point &other) const{
        return x*other.x + y*other.y + z*other.z;
    }
};
